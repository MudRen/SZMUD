//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "������");
	set("long",  @LONG
�������Ͻ������־�פ����Ϣ�ط���һ���ŵ�ͨ�̿���ǽ���ţ�
���ڳ�����Ϊ���ӣ�����ط��䲻�󣬵���Ȼס���������ˡ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"wuyingmen",
	]));

	setup();
	replace_program(ROOM);
}
