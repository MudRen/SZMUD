//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","Ȩ����ֶ�");
	set("long",@LONG
����������ڷ���һ�������磬�����ϻ���һ���ͻ���ɽͼ�����ϻ���Щ��λ��������
��һλ�������ӡ�һЩ������æ�Ű����ڷŶ�������˵������λ��Ҫ����Ҫ�����������Ĵ�
�߶������ҵ������ġ�
LONG
	);
	set("exits",([
		"east" : __DIR__"nroad2",
	]));

	setup();
}
