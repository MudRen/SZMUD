// Code of ShenZhou
// Room: /d/dali/wangfu11.c

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
ֻ����䷿������ǵ������ľ�壬�����ư��𡹣����꺮���ѡ�����
ɽˮ�������ë���ܣ��򼯽����򲩹ţ��������٣����ֻ����������ֵ��Σ�
�������Ƕ���ġ�һ��һ�����������鴦�����趦�������ñ��⴦��������ƿ
�����辰��������ʽ����������Բ�ط����������Ҷ����������ڣ����ǻ���
���أ���͸���硣ٿ����ɫɴ���ͣ���ϵС����ٿ������Ḳ����ϵ�Ļ�������
ǽ��ϵ����֮�οٳɵĲ��ӣ������١�������ƿ����֮�࣬�����ڱڣ�ȴ������
����ƽ�ġ�
LONG);
	set("objects", ([
		"/kungfu/class/dali/zhudanchen" : 1,
		"/kungfu/class/dali/weishizhang" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"wangfu9",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
