// July 31,2000
// Code by April
// /gumu/kongdi.c

inherit ROOM;

void create()
{
        set("short","�յ�");

        set("long",@LONG
��������ɽɽ������һ��յأ�����ƽ̹������һ��С·ֱ��ɽ�ڶ�
�ϣ�ͨ��������ɽ���塣�ϱ�һ��Ƭ���֣�ֻ��Ȫˮ���ˣ�����������
��Ʈ����ܰ����Ƣ��һ��ʯ��(shibei)���ڵ��ۨ洦��һЩ��̦��������
�档������һ��ɽ·��������һ��С����
LONG);

        set("item_desc",(["shibei" : "

                        ����ɽ��Ĺ��
                        ������ֹ����

\n",]));

        set("exits",([ "northup" : "/d/zhongnan/shanlu12",
                                "south" : __DIR__"milin0",
                      ])
           );
          set("cost",1);
          set("outdoors", "gumu");

        setup();
        replace_program(ROOM);
}

