// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "�軨ɽ");
	set("long", @LONG
��վ��һ��Сɽ������£�����ʢ���軨����Ʒ�ֵĲ軨��
���������������ƬСɽ��Ҳ�����˺ò衣���߲�Զ���Ǵ����
�ı����ˡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"northgate.c",
		"eastup" : __DIR__"chhill1.c",
		]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
