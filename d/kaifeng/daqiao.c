//Room: /d/kaifeng/daqiao.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����ǿ��⸮���������š����Ӻ��ϺӼг��������ǻ����������
����͹���֮�ء���ˮ���±�͸���м�β����ں��ﳩ������ţ�����С
�����ű���Ϸ�����߾�Ҫ�������ţ����������һƬ���ƺӳ�ˢ֮���ɳ�ء�
LONG
        );

        set("exits", ([
                "east" : __DIR__"dadao",
                
  "west" : "/d/xixia/mszhou",
              ]));
        set("fjing", 1);
        set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}
