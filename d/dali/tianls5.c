//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "��ĸ��");
        set("long", @LONG
��ĸ��ռ�ؿ�󣬵�������ʮ��֧��������ʮ��������ľ��һ�����֣�
����Ϳ���Ƿ�����ɫ�Ĵ��ϣ������������������ڻԻͣ����ܷ����Ϊ
�ƽ𣬹�����Ƕ�����ɱ�ʯ����ֵ���ǡ�����ǰ��̨��Ҳ�����أ���˵һ��
ֻ�������þż���ֻ����߸ߣ��ų߳����ų߿�ȴ�Ǵ�һ�������ʯ����
���ġ�
LONG
        );
        set("exits", ([
		"north" : __DIR__"tianls6.c",
        "southdown" : __DIR__"tianls4.c",		]));
set("no_clean_up", 0);
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

