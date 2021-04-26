// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "һ����");
	set("long", @LONG
����ڷ���ɽ��Լ�����������һ���š�������һ����׷������˴˷���
�����˵�̩ɽ���̵���������һ������ͤ��ʿ����Ǽ�����ӣ����������ﻻ��
���ķ�װ���ż�����ɽ����һ��������������������ʮ����������������
�����֣���̩ɽ���˵������й�ֹ֮̾��������һ�Ʒ�����д�����ӵ��ٴ�����
�ഫΪ�����ӹ�̩ɽ�ࡹ�Ĺ��·����ĵط���
LONG
	);

	set("exits", ([
		"northup" : __DIR__"doumo",
		"southdown" : __DIR__"baihe",
		"southeast" : __DIR__"tingyu",
	]));

	set("objects",([
		__DIR__"npc/dao-ke" : 1,
	]));

	set("outdoors", "taishan");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

