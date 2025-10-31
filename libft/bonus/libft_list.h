/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:45:55 by imengels          #+#    #+#             */
/*   Updated: 2025/10/22 13:45:57 by imengels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct s_clist
{
	void			*content;
	bool			head;
	struct s_clist	*next;
}					t_clist;

typedef struct s_dclist
{
	void			*content;
	bool			head;
	struct s_dclist	*next;
	struct s_dclist	*prev;
}					t_dclist;

/***********************LST**********************/
/*		lst_add				*/
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *node);
void				ft_lstadd_back(t_list **lst, t_list *node);
/*______________________________________________*/

/*		lst_rm				*/
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
/*______________________________________________*/

/*		lst_util			*/
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
/*______________________________________________*/
/************************************************/

/***********************DLST*********************/
/*		dlst_add			*/
t_dlist				*ft_dlstnew(void *content);
void				ft_dlstadd_front(t_dlist **dlst, t_dlist *node);
void				ft_dlstadd_back(t_dlist **dlst, t_dlist *node);
void				ft_dlstadd_after(t_dlist *dlis, t_dlist *insert);
/*______________________________________________*/

/*		dlst_rm				*/
void				ft_dlstdelone(t_dlist *dlst, void (*del)(void *));
void				ft_dlstclear(t_dlist **dlst, void (*del)(void *));
t_dlist				*ft_dlst_unwrap(t_dlist **head, t_dlist *node);
/*______________________________________________*/

/*		dlst_util			*/
int					ft_dlstsize(t_dlist *dlst);
t_dlist				*ft_dlstlast(t_dlist *dlst);
void				ft_dlstiter(t_dlist *dlst, void (*f)(void *));
t_dlist				*ft_dlstmap(t_dlist *dlst, void *(*f)(void *),
						void (*del)(void *));
/*______________________________________________*/
/************************************************/

/***********************CLST*********************/
/*		clst_add			*/
t_clist				*ft_clstnew(void *content);
void				ft_clstadd_front(t_clist **clst, t_clist *node);
void				ft_clstadd_back(t_clist **clst, t_clist *node);
/*______________________________________________*/

/*		clst_rm				*/
void				ft_clstdelone(t_clist *clst, void (*del)(void *));
void				ft_clstclear(t_clist **clst, void (*del)(void *));
/*______________________________________________*/

/*		clst_util			*/
int					ft_clstsize(t_clist *clst);
t_clist				*ft_clstlast(t_clist *clst);
void				ft_clstiter(t_clist *clst, void (*f)(void *));
t_clist				*ft_clstmap(t_clist *clst, void *(*f)(void *),
						void (*del)(void *));
/*______________________________________________*/
/************************************************/

/***********************DCLST********************/
/*		dclst_add			*/
t_dclist			*ft_dclstnew(void *content);
void				ft_dclstadd_front(t_dclist **dclst, t_dclist *node);
void				ft_dclstadd_back(t_dclist **dclst, t_dclist *node);
/*______________________________________________*/

/*		dclst_rm			*/
void				ft_dclstdelone(t_dclist *dclst, void (*del)(void *));
void				ft_dclstclear(t_dclist **dclst, void (*del)(void *));
/*______________________________________________*/

/*		dclst_util			*/
int					ft_dclstsize(t_dclist *dclst);
t_dclist			*ft_dclstlast(t_dclist *dclst);
void				ft_dclstiter(t_dclist *dclst, void (*f)(void *));
t_dclist			*ft_dclstmap(t_dclist *dclst, void *(*f)(void *),
						void (*del)(void *));
/*______________________________________________*/
/************************************************/

#endif
