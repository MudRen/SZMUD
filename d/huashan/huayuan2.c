// Code of ShenZhou
// huayuan2.c

inherit ROOM;

void create()
{
	set("short", "��ɽС��");
	set("long", @LONG
������һ��С԰�ӣ���ͷ�и�С���������ܲ��м�ɽ��������԰������
����ʱ��ˮ����Ϫ���У�����ˮ���������������̰��ö���ˮ��������
̧ͷ������ֻ��Զ����ɽ���죬�������֣��꾰��Ȥ���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "east" : __DIR__"houyuan",
	    "northeast" : __DIR__"huayuan",  
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}