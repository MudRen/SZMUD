// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "�׻�̳");
	set("long", @LONG
�����Ƿ���̨���Ͻǵİ׻�̳�������׻�̳�Ǹ����εĹ㳡��
���е�����վ��һͷ�׻����ƺ������麺�����ɣ������޶
�������ݡ��׻�����������צ�������˸��ף�һ����֪���Ǽ�Ϊ
����֮�
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"fengchan",
		"east" : __DIR__"xiayi",
	]));

	set("outdoors", "taishan");
	setup();

	replace_program(ROOM);
}

