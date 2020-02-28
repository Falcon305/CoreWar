/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 12:27:16 by hrazani           #+#    #+#             */
/*   Updated: 2020/02/27 20:00:13 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>


# define BLACK(x) "\033[30;1m" x "\033[0m"
# define RED(x) "\033[31;1m" x "\033[0m"
# define GREEN(x) "\033[32;1m" x "\033[0m"
# define YELLOW(x) "\033[33;1m" x "\033[0m"
# define BLUE(x) "\033[34;1m" x "\033[0m"
# define MAGENTA(x) "\033[35;1m" x "\033[0m"
# define CYAN(x) "\033[36;1m" x "\033[0m"
# define WHITE(x) "\033[37;1m" x "\033[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct		s_addr
{
	void			*addr;
	struct s_addr	*next;
}					t_addr;

typedef struct		s_queue
{
    t_addr          *first;
    t_addr         	*last;
}					t_queue;

# define BUFF_SIZE 32

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *src, int c);
char				*ft_strrchr(const char *src, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strnjoin(char *s1, char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_is_even(int c);
int					ft_is_prime(int nb);
int					ft_sqrt(int nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isgraph(int c);
int					ft_isprint(int c);
int					ft_iscntrl(int c);
int					ft_isspace(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_min(int x, int y);
int					ft_max(int x, int y);
int					ft_countword(const char *word);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(const char*s1, const char *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_btree				*btree_create_node(void *item);
void				btree_insert_data(t_btree **root, void *item,
										int (*cmpf)(void *, void *));
int					get_next_line(int const fd, char **line);
void				swap(int *x, int *y);
void				ft_error(char *error_msg);
t_addr				*ft_new_t_addr(void *addr);
void				ft_free_t_addr(t_addr *head);
t_addr				*ft_push_t_addr(t_addr *head, void *addr);
t_addr				*ft_remove_t_addr(t_addr *head, t_addr *node);
t_queue				*ft_new_queue(void);
void				ft_enque(t_queue *q, void *data);
void				ft_pop(t_queue *q);
int					ft_free_queue(t_queue *q);

#endif
