// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ����ש��ǽ�ĳ��ȣ����¼ž�������������Щ���¡����߾�ͷ��
һ���ڳ��������ţ�������ׯ�����ӵ����߸�
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"changlang1",
	    "west" : __DIR__"lingshege",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
