//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "�嶼��̨");
        set("long", @LONG
������ȫ��ɮ�¾Ӽ������µĳ��������ܶ��Ǵ���ĺ����񡣾���һ��
��̳������������ɢɢ���������ģ���ʮ�����š�������������һ��Ī����״
������֮�С�����������ʮ���ࡣǰ�����Ҹ���ʮ�������������ĺܡ�
LONG
        );
        set("exits", ([
		"northup" : __DIR__"tianls5.c",
        "southdown" : __DIR__"tianls3.c",		]));
set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

