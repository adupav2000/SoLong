/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_macos.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pavi <adu-pavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:37:57 by myoung            #+#    #+#             */
/*   Updated: 2021/10/10 14:12:04 by AlainduPa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_MACOS_H
# define KEYCODE_MACOS_H

# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_F 102
# define KEY_H 103
# define KEY_Q 113
# define KEY_W 119
# define KEY_E 101
# define KEY_R 114
# define KEY_Y 121
# define KEY_T 116
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_UP 65362
# define KEY_ESC 65307

typedef struct s_keys
{
	int a : 1;
	int s : 1;
	int d : 1;
	int f : 1;
	int h : 1;
	int g : 1;
	int z : 1;
	int x : 1;
	int c : 1;
	int v : 1;
	int b : 1;
	int q : 1;
	int w : 1;
	int e : 1;
	int r : 1;
	int y : 1;
	int t : 1;
	int one : 1;
	int two : 1;
	int three : 1;
	int four : 1;
	int six : 1;
	int five : 1;
	int nine : 1;
	int seven : 1;
	int eight : 1;
	int zero : 1;
	int brace_r : 1;
	int o : 1;
	int u : 1;
	int brace_l : 1;
	int i : 1;
	int p : 1;
	int l : 1;
	int j : 1;
	int k : 1;
	int semi : 1;
	int n : 1;
	int m : 1;
	int tab : 1;
	int plus : 1;
	int minus : 1;
	int left : 1;
	int right : 1;
	int down : 1;
	int up : 1;
} t_keys;

#endif
