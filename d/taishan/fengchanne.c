// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "����̳");
	set("long", @LONG
�����Ƿ���̨�����ǵ�����̳����������̳�Ǹ����εĹ㳡��
���ϣ������˸�������һͷ�޴��ʯʨ���ߴ����࣬�������Ժ�
�����ݴ�ʯʨ���׸��С����족�����������֣����˾������е���
ִ�����µĴ�ӡ��
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"fengchan",
		"east" : __DIR__"xiayi",
	]));

	set("outdoors", "taishan");
	setup();

	replace_program(ROOM);
}
