// Code of ShenZhou

// road: /zhongnan/shanfeng.c

inherit ROOM;

void create()
{
        set("short","����ɽ����");

		  set("long",@LONG
��ʱ������������ɽ���壬��Ұ��Ϊ������������ȥ��Ⱥɽ��������
�ڽ��¡��������Ĵ���������ɽ��������Ө���ԡ�ֻ�����ٵ���ɢ���ɽ
��䣬��ɫ��Ϊ���һ���ʯ(shi)����һ�ԣ��ƺ�����ʲ�ᶫ��������
���ϸ���һ��ɽ·��
LONG);

        set("item_desc",(["shi" : "

		�����������Ҫ����
		�񴫼������˰麺��
		���븴Ӣ����࿪־
		�ϵ�֪��ȫ���ɺ���
		ɽ�����������ξ���
		������������������
		����ճ˸��칦����
		������ʱ�����Ȼ��
		��˻���Բ�������
		��������������һ��
		����Ĺ�ݲ���ȥ����
		������������������

\n",]));

        set("exits",([ "westdown" : __DIR__"shanlu11",
                        "southdown" : __DIR__"shanlu12",
                      ])
           );
           set("objects", ([
                "/d/zhongnan/npc/xiucai" : 1,
        ]));
	  set("cost",3);
        set("fjing", 1);
	  set("outdoors", "zhongnan");

        setup();

        replace_program(ROOM);
}