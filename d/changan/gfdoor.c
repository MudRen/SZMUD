//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","����");
	set("long",@LONG
���ſ�վ�ż�λ���ۣ�����Ĺ�̩�񰲣�������Ҳ���˺ܶ����ˮ�ĵط���
������˵Ц�ţ����ſ�û��һ�������У�����ƽ���ϰ���Ҫ���������ǿ�
�ǿɾͲ������ˡ�
LONG
	);
	set("exits",([
		"southeast" : __DIR__"xfroad2",
		"northwest" : __DIR__"qianyuan",
	]));

      set("objects",([__DIR__"npc/bing":3,]));
	setup();
}
