//Room: /d/kaifeng/wroad2s.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�������ڿ��⸮��������ϣ�����һ���������Ĵ�·��������
һֱ���졣·�����������������ò����֡�С��С������������ЩС
�����������ɼ��������Ÿ�ͷ��������䡣
LONG
        );

        set("exits", ([
                "southwest" : __DIR__"xilin",
                "southeast":__DIR__"sroad2w",
                "north":__DIR__"wroad2",
              ]));

         set("objects",([
                __DIR__"/npc/liumang":1,
             ]));
         set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}
