//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�������Ĳ����֣�����ԶԶ������һ�Ų��̵��ɰأ������
�����߽�Щ��һ����ˬ֮������������������ף�������������߽�
Щ���Ϳ����ᵽ��Ժ���е����㣬�ɰشԼ䣬¶��һ�Ƿ��ۣ�����ϸ
����������������ԭ��������
LONG
        );
        set("exits", ([
		"out" : __DIR__"tianls1.c",
        "enter" : __DIR__"tianls2.c",		]));
set("no_clean_up", 0);
        set("cost", 3);
        setup();
        replace_program(ROOM);
}

