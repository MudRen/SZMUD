// Code of ShenZhou
// room: /mingjiao/longquangu.c

inherit ROOM;

void create()
{
        set("short", "��Ȫ��");
        set("long", @LONG
һ��������ɽ���У��������Ӳݼ�����һ�˶�ߡ��������������
��·ȴ�����ҹգ���û�ѱ档�������ҡ�ڣ��������ص�Ҳ���н��ɡ���
����һ����ɽ��
LONG );

        set("exits", ([
                "northeast" : __DIR__"qingshuigou",
                "westup" : __DIR__"douxian",
                "northup" : __DIR__"xingzi",
        ]));

        set("outdoors", "mingjiao" );
	set("resource/grass", 1);
	set("cost", 1);

        setup();
        replace_program(ROOM);
}