// Code of ShenZhou
// Room: /d/dali/dalicheng7.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����ض���һɽʯ������Ȼ�Ļ��ƶ��������£��Ǳ��Ǵ��������Ĵ���ʯ��
�ô���ʯ�е�ˮī��ʯ�����Ļ�����������̶ȣ�ʹ��̾Ϊ��ֹ������ʱ������
����̽��嶼ϲ���Դ���ʯ���ҾӰ��衣ʯ������ͷ�üã��ô���ĥ֮��������
����һ��������ͷ���Ű��ӣ���������С����ָ�����»�ơ�
LONG);
	set("objects", ([
		__DIR__"npc/shijiang" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"dalicheng5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
