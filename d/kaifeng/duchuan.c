// Code of ShenZhou
// Room: /d/kaifeng/duchuan.c
// chchong 2002/02/01

inherit ROOM;




void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ�����������
�ֳֳ���ݣ����ڴ�β�����س��Ŵ���
LONG
	);


        set("outdoors", "kaifeng");
	set("cost", 2);
	set("invalid_startroom", 1);
	setup();
	replace_program(ROOM);
}



