// Code of ShenZhou
// baza ����
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����ǰ��������ߣ������Ļ�Ʒ��  �ࡢ��ۡ����ա�ţ��
���ϡ�Ƥ�ľ�ĵȵȡ�ɢ�Ӹ��ص�ά��������ũ�����˶����ڴ�
�ϼ����ף��˳����ﲻ����
LONG
	);
	set("exits", ([ 
            "east" : __DIR__"baza1",
	]));
	set("objects", ([ 
	    "/d/xingxiu/npc/zaierger" : 1,
//	    "/d/xingxiu/npc/w-girl" : 1,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
