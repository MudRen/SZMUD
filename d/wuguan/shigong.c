//Creatived by Snso
// /d/wuguan/shigong.c
//�Թ���

inherit ROOM;

void create()
{
                  set("short", "�Թ���");
                  set("long", @LONG
������Ȫ����ݵ��Թ��ң��������м���ľ�˺ͼ����ű����ļ��ӣ����
���������ﻥ���д����գ������ĵ�����Ա�ӿ��������ٶȡ�
LONG
                  );
                  set("valid_startroom", 1);

                  set("exits", ([
                  "northwest" : __DIR__"zoulang4",
                  ]));

                set("cost",1);


                setup();
}
