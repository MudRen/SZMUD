//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","ǰԺ");
	set("long",@LONG
����ǰԺ�͵������������ˡ�Ժ�ӱ��ϰ���Щ�������Ա߻���Щɳ������
�ǽ������ε�֪���������µĹ�أ�ÿ�����۶�Ҫ�������ӹǡ�������������
�����ڴ�ɳ����
LONG
	);
	set("exits",([

		"west" : __DIR__"zhengting",
		"southeast" : __DIR__"gfdoor",
	]));

	setup();
}
