// Code of ShenZhou 
// /kunlun/shufang2.c
// by keny

#include <ansi.h>
inherit ROOM; 

string* books = ({
"laozi1",
"daodejing-i",
"laozi2",
"daodejing-ii",
"laozi8",
"daodejing-i",
"laozi13",
"daodejing-ii",
"laozi18",
"daodejing-i",
"daodejing-ii",
"laozi16",
});

void create() 
{
set("short", WHT"�鷿��"NOR);
set("long",@LONG 
�������鷿������ǽһ�Ŵ���ܣ��ڷ��źܶ���鼮��������ʥ�������
��ѧΪ�ޣ���������һֱ���Ե�ѧ�ķ������ķ���һ������ȥ���ƺ��й��� 
��ѧ������飬��������ϡ�
LONG
);

set("exits", ([ 
"west"  : __DIR__"shufang",
]));
set("cost",1); 
set("objects", ([ 
"/d/zhongnan/obj/"+books[random(sizeof(books))] : 1,
"/d/zhongnan/obj/"+books[random(sizeof(books))] : 1,
"/d/kunlun/obj/taoism.c" : 1
]));
setup();
replace_program(ROOM); 
}

