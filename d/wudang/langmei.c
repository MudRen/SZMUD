// Code of ShenZhou
// langmei.c ��÷԰ 
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "��÷԰");
	set("long", @LONG
	������������÷������ɫ��ǳһ���һ����ٴ�˿������״���ƺ�÷����ɽ
�е����������ഫ��һ������۰�÷֦�����Ƹ��ϣ��ö����ϣ��ɴ����֡���˵��
÷���˲����Դ����䵱ɽ��Υ�߱��ⲻ����
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northup" : __DIR__"taiziyan",
		"southup" : __DIR__"wuyaling",
                "westup" : __DIR__"nanyan",
	]));
        set("objects", ([
                CLASS_D("wudang") + "/shouyuan" : 1]));
	set("cost", 2);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

