// Code of ShenZhou
// Room: /d/xiangyang/jzjie1.c

inherit ROOM;

void create()
{
        set("short", "���ݽ�");
        set("long", @LONG
�ߵ��˴������ǵ��˾���·�ף�������ȥ����������һ�ȸ��ڴ��ţ�����ס��һλ
�˲������������в��ٵĽ�����ʿ��������˵��Ϊ�����������������˴��ķ����
������
LONG
        );
        set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : -1 ]) );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dongjie2",
  "south" : __DIR__"guofu",
]));
        set("outdoors", "xiangyang");

        setup();
        replace_program(ROOM);
}
