// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "��ȸ̳");
	set("long", @LONG
�����Ƿ���̨�����ǵ���ȸ̳��������ȸ̳�Ǹ����εĹ㳡��
���ܽ��ϸ�����һ��Ѫ��Ĵ��졣������������ȸ�ı�־������
�����Ի���̳�л�ȼ����һ�������һ���ӭ�����Ĵ�����
��ӳ��
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"fengchan",
		"west" : __DIR__"zhengqi",
	]));

	set("outdoors", "taishan");
	setup();

	replace_program(ROOM);
}

