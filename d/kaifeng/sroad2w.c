//Room: /d/kaifeng/sroad2w.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
�������ϴ�ּ�ʵ����ʯ������ϣ���ɫ�˵��������У�������
�֡���ʱ����ܻ����һЩ����װ����������ǿ������죬����Ҳ
�廨���ţ��������������㣬�ɲ��Ǻ��ǵġ����������Ĵ��������
��֡����Ϸ��Ǹ���Ρ��Ľ���Ⱥ���˽��˳���ʮ�����֡�����ͨ��
����֡�
LONG
        );

        set("exits", ([
                
                "northwest":__DIR__"wroad2s",
                "east":__DIR__"sroad2",
                
              ]));
       set("outdoors", "kaifeng");
               

        setup();
        replace_program(ROOM);
}
