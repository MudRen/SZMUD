// Code of ShenZhou
// Room: 
// Date: 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǹ���ׯ½��ׯ����������������½��ׯ����������֧
��ϼ�ɳ������Է��в��þ���Ϊϰ������Ӳ��֮�ã������Ų�
��ľ׮�ͲݰС����߽��ϻ���������ɳ�ӣ��컨���ϵ���һ֧��
ɳ����
LONG
	);

	set("exits", ([
		"west" : __DIR__"huayuan",
	]));


	set("objects",([
//		    __DIR__"npc/xiaoping" : 1,
//                __DIR__"npc/mu-ren" : 1
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

