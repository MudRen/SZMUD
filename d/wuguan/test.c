//Modified by Lisser
// Room: test.c �����

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "���м����");
    set("long", @LONG
��������ݿ�ʼ�����ڼ����ݵ��ӹ��򣬱�֤��ʦ�������ڽ�����
���㡣ǽ�ϵ������������������˺ۣ�Ӧ������ݳ�ʦ��ǰ�������µġ�
���ڸ��������е������Ƹ���ĸ�����硣
LONG
    );
    
	set("objects", ([
		__DIR__"npc/tester" : 1,
	]));

	set("no_clean_up", 0);
	set("sleep_room", 0);
	set("no_fight", 1);
	set("no_steal", 1);
	set("cost", 1);

	setup();
}
