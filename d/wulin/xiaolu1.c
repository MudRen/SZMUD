// room /d/wulin/xiaolu1.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
�뿪�������У���ɫת�����ģ��������Ҳ��֮����������������С
·��ֱͨ�������кպ�����������ʹ�ߵľӴ������ɵüӿ��˽Ų�������
������ͬ�˵ĵ��š�
LONG
        );

        set("exits", ([
         "east" : __DIR__"dianmen",
         "west" : __DIR__"xiaolu2",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
