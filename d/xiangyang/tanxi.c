// Code of ShenZhou
// Room: /d/xiangyang/tanxi.c

inherit ROOM;

void create()
{
        set("short", "��Խ̴Ϫ��");
        set("long", @LONG
�ഫ����ĩ�꣬�������Խ��ı��ɱ���������˸�֪���������Ƕ�������
Ϫ�ߣ����˰ڶɣ������������С�׷����������������������¬һԾ����ɹ�
Ϫȥ������ʯ������һ��������ѣ������������ɼ���
LONG
        );
        set("outdoors", "xiangyang");
        set("no_clean_up", 0);
        set("coordinates", ([ "x" : -10, "y" : 0 ]) );
        set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"tulu3",
  "west" : __DIR__"diluqiao",
]));

        setup();
        replace_program(ROOM);
}
