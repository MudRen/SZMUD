// Code of ShenZhou
// /d/huanghe/tctuwu.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��С���ݣ���������һ������ķ��ӡ�����򵥵ذ���Щ�Ҿ�
��ǽ�������������һЩ�����ҳ��ļҾߺ��������������Ѿ��ܾ�û����
�˾�ס�ˡ�
LONG );

        set("exits", ([
		"west" : __DIR__"tcxiaolu",
        ]));

    	set("cost", 1);

        setup();
        // replace_program(ROOM);
}
