//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "��˼��");
	set("long",  @LONG
�������־��ܽ�ͷ���޵ǽ�Ϲ���һ�ѱ�����һ�Ź�����ǽ��
б����һ�˳�ǹ������ɢ���ż������ţ����������������ڹ�ʱ�õġ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"gzxd2",
		"south" : __DIR__"wuyingdian",
	]));

	setup();
	replace_program(ROOM);
}