// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��ɽ�в�");
	set("long", @LONG
�������ڲ�ɽ�в�ɽ�ߣ��˼���μ��գ�����ɽ�����ƣ��м�һ
����᫲�ƽ��ɽ·��·����Զһ������Ա���ƫ��������������¡¡
ˮ��ңң���ţ�������گ����--��ˮ����·��������������������
�ؾ�֮;��ʱ�п��̹������ɴ����ϴ�Խ��ɽ�ɵ��¹سǣ����治Զ
���ǳ���ɽ��ɽ�ڡ�
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov89",
		"southwest" : __DIR__"minov91",
		"southeast" : __DIR__"xiaguan",
		]));

	set("outdoors","dali");
       set("fjing", 1);
	set("cost", 3);
	setup();
}
