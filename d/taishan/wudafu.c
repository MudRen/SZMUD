// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�ഫ������ʼ����̩ɽ�����������������������͵���������
���±��꣬���û���š���ˣ����ͷ�����������Ϊ�����򡹡�
������֪����������һ��޴�ķ���ʯ���������������ˡ�������
���Բ��������������ڲ�Զ������һ������ƺ����˵������ʼ�ʵ�
����ʵ�λ�á�����������ɽ���߱�ᵽ��ʮ���̵���ڡ�
LONG
	);

	set("exits", ([
		"northup" : __DIR__"longmen",
		"southdown" : __DIR__"ertian",
	]));

	set("objects",([
		__DIR__"npc/meng-mian" : 1,
	]));

	set("outdoors", "taishan");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

