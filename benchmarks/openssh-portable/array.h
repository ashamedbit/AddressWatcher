#define ARRAY_INITIALIZER { NULL, 0, 0 }

#define ARRAY_DECL(n, c)						\
	struct n {							\
		c	*list;						\
		u_int	 num;						\
		size_t	 space;						\
	}

#define ARRAY_ITEM(a, i) ((a)->list[i])
#define ARRAY_ITEMSIZE(a) (sizeof *(a)->list)
#define ARRAY_INITIALSPACE(a) (10 * ARRAY_ITEMSIZE(a))

#define ARRAY_ENSURE(a, n) do {						\
	if ((1 << 30) - (n) < (a)->num)					\
		fatalx("number too big%s", "");				\
	if ((1 << 30) / ((a)->num + (n)) < ARRAY_ITEMSIZE(a))		\
		fatalx("size too big%s", "");					\
	if ((a)->space == 0) {						\
	       	(a)->space = ARRAY_INITIALSPACE(a);			\
		(a)->list = xrealloc((a)->list, 1, (a)->space);		\
	}								\
	while ((a)->space <= ((a)->num + (n)) * ARRAY_ITEMSIZE(a)) {	\
		(a)->list = xrealloc((a)->list, 2, (a)->space);		\
		(a)->space *= 2;					\
	}								\
} while (0)

#define ARRAY_EMPTY(a) (((void *) (a)) == NULL || (a)->num == 0)
#define ARRAY_LENGTH(a) ((a)->num)
#define ARRAY_DATA(a) ((a)->list)

#define ARRAY_FIRST(a) ARRAY_ITEM(a, 0)
#define ARRAY_LAST(a) ARRAY_ITEM(a, (a)->num - 1)

#define ARRAY_INIT(a) do {						\
	(a)->num = 0;							\
	(a)->list = NULL;		 				\
	(a)->space = 0;							\
} while (0)
#define ARRAY_CLEAR(a) do {						\
	(a)->num = 0;							\
} while (0)

#define ARRAY_SET(a, i, s) do {						\
	(a)->list[i] = s;						\
} while (0)

#define ARRAY_ADD(a, s) do {						\
	ARRAY_ENSURE(a, 1);						\
	(a)->list[(a)->num] = s;					\
	(a)->num++;							\
} while (0)
#define ARRAY_INSERT(a, i, s) do {					\
	ARRAY_ENSURE(a, 1);						\
	if ((i) < (a)->num) {						\
		memmove((a)->list + (i) + 1, (a)->list + (i), 		\
		    ARRAY_ITEMSIZE(a) * ((a)->num - (i)));		\
	}								\
	(a)->list[i] = s;						\
	(a)->num++;							\
} while (0)
#define ARRAY_REMOVE(a, i) do {						\
	if ((i) < (a)->num - 1) {					\
		memmove((a)->list + (i), (a)->list + (i) + 1, 		\
		    ARRAY_ITEMSIZE(a) * ((a)->num - (i) - 1));		\
	}								\
	(a)->num--;							\
	if ((a)->num == 0)						\
		ARRAY_FREE(a);						\
} while (0)

#define ARRAY_EXPAND(a, n) do {						\
	ARRAY_ENSURE(a, n);						\
	(a)->num += n;							\
} while (0)
#define ARRAY_TRUNC(a, n) do {						\
	if ((a)->num > n)						\
		(a)->num -= n;				       		\
	else								\
		ARRAY_FREE(a);						\
} while (0)

#define ARRAY_CONCAT(a, b) do {						\
	ARRAY_ENSURE(a, (b)->num);					\
	memcpy((a)->list + (a)->num, (b)->list, (b)->num * ARRAY_ITEMSIZE(a)); \
	(a)->num += (b)->num;						\
} while (0)

#define ARRAY_FREE(a) do {						\
	free((a)->list);						\
	ARRAY_INIT(a);							\
} while (0)
#define ARRAY_FREEALL(a) do {						\
	ARRAY_FREE(a);							\
	free(a);							\
} while (0)

