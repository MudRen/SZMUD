// Code of ShenZhou
// xuanya.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǻ�ɽ�������ϵ�һƬƽ̨�������ն�ƽ̨�Ա���������Ԩ����
ͷ���£�ֻ��һ���ƺ�����ɽ���Ӷ��ڴ���������������ʱ���ƣ�������
����ƽʱ��ɽ����Ҳ�ڴ�ָ�㼰�������µ��ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	    "west" : __DIR__"houyuan",
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}