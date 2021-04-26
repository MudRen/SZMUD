// Code of ShenZhou
// Room: /d/wizard/meeting_room.c

inherit ROOM;

void create()
{
        set("short", "���;�����");
        set("long", @LONG
���Ǽ�޴��Բ�λ��������ӵ��浽�컨�嶼�������ˮĥ���滨��ʯ����
�������и����ķ�����ˮ�أ�ˮ�����������һֻ���˸ߵ�ͭ�ꡣ�걳�Ϸ��ſ�
ǧ��ʯ����������д�����ɷ�����������֣������ݡ�������ˮ��������������
�ĸ�������ڷ��žŰѻ�Ƥ���Σ�����Ż�����������ˮ�ء����ܵ�ǽ���ο���
һЩ�Źֵ����֡��Ա߻��������ڣ����Ե���һЩС��ģ�Ļ����ҡ�
LONG );

        set("exits", ([
"ctrl"  : "/family_job/control.c",
        "up" : __DIR__"station_room",
        "down" : __DIR__"wizard_room" ]));
        set("item_desc", ([ 
        "map":
        "general:ͨ������뿪�����ɵĻ����ң������ƶ��ͼල��Ŀ���ȵĵط�\n"+
        "kungfu :ͨ�������ܻ����ң����ǽ����书�����ܺͱ�̾���ĵط�\n"+
        "quest  :ͨ�������������ң����ǽ������⡢��ڡ�������������ƺͱ�д����ĵط�\n"+
        "npc    :ͨ���������������ң����ǽ���������������ƺͱ�̾���ĵط�\n"+
        "obj    :ͨ����Ʒ���߻����ң����ǽ���������Ʒ���ߵ���ƺͱ�̾���ĵط�\n"+
        "test   :ͨ�����Ե�������ң����ǽ����´�����ԡ���Ϸ��Դ����Ⱦ���ĵط�\n"+
        "room   :ͨ����ͼ��������ң����ǽ�����ͼ�����䡢���ص���ƺͱ�̾���ĵط�\n"+
        "job    :ͨ������ϵͳ�����ң����ǽ�������ϵͳ��ְҵϵͳ����ƺͱ�̾���ĵط�\n"+
        "guide  :ͨ����ͼ��ݣ�����ѧϰ�����С��߼����֪ʶ������ϯ�����������ʵĵط�\n",
        ]));

        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("cost", 0);
        setup();
	call_other("/clone/board/admin_b", "???");
	call_other("/clone/board/project_b", "???");
	

//      call_other("/clone/board/progress_b", "???");
//      replace_program(ROOM);

}
void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
