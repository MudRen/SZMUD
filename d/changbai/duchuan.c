// Code of ShenZhou
// Room: /d/shaolin/duchuan.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ�����������
�ֳֳ���ݣ����ڴ�β�����س��Ŵ���
LONG
	);


	set("outdoors", "shaolin");
	set("cost", 2);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}



