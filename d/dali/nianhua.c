// Code of ShenZhou
inherit ROOM;




void create()
{
        set("short", "�黨��");
        set("long", @LONG
һ��СС�Ĺ�������ش�ƫƧ���������һ����������
�����ƴӺ�Ժ��������ֻ�б����������⾲���С�
LONG
        );

        set("objects",([
                "/d/dali/npc/xiao-ku" : 2
        ]));

        set("cost", 1);
	 setup();
}
int valid_leave(object me, string dir)
{
        if( !present("xin", me) )
                return 
notify_fail("Сɳ����ǰһ��˵����������Ŵ�ʦ���ޣ�\n");

        return ::valid_leave(me, dir);
}


