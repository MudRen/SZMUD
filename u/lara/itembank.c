// ��Ʒ����
// /d/city/itembank.c
// Code by Scatter
// 2001/10/24
// V. 1.0
// Lara 2001/12/05
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"��Ʒ�ķŴ�"NOR);
set("long", @LONG
��������������Ʒ�õķ��䡣���зֱ�ڷ��˴�С��ͬ������
��ľ�䡣ľ����������������������һЩ������Ʒ�Ƶġ��㳣
����һ����������֮��������ȥ����С�ĵĿ��������ϵ���Ʒ��
��˵��������������Ŀ�����Ʒ�����ˡ�
LONG
        );
set("objects", ([ __DIR__"npc/wanzitian.c" : 1,   ]) );

 set("exits", ([
                "west" :__DIR__"qianzhuang.c",
               "southwest" : __DIR__"dongdajie3",
        ]));

            set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
setup();
replace_program(ROOM);
}
