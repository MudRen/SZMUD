//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������µ�ǰͥ�������嶼��̨����ʯ����������������������ͩ��
��Ҷ���ģ�����ͥԺ��ˬ�ޱȡ���ʯ��·�����������Ժ��û��������ɫ�Ļ�
�ܣ�û�����ֵ���Ⱥ������û��ɮ�������ʵ������ֻ��һƬ�ž���Ȼ����
��Ƭ�ž��У�ȴ��������һ��ǿ�ҵ���������
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
		"northup" : __DIR__"tianls4.c",
        "westdown" : __DIR__"tianls2.c",		]));
 set("cost", 3);
        setup();
        replace_program(ROOM);
}

