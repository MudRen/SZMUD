//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","���������");
	set("long",@LONG
���ڴ�ʯ����ϣ������ı��ֱȽ�����,·�ϵ����˽��١����紵��,����ë���Ȼ��
�����Ǹ�Ǯׯ�������߾��ǳ����ǵ���վ�������Ǹ�Զ�����������˺��Ѽ�ȥο�ʺ͹ػ�
�ĵط�������ǰ�߾ͳ��˳������ˡ�
LONG
	);
	set("exits",([
		"east" : __DIR__"yizhan",
		"west" : __DIR__"qianzhuang",
		"south" : __DIR__"nroad2",
		"north" : __DIR__"beimen",
	]));
set("outdoors", "changan");
	setup();
}
