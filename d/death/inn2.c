// Code of ShenZhou
// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "�ڵ�");
        set("long", @LONG
�����൱����, �����Ũ����ʱ�شӰ뿪�����ŷ�Ʈ����,
������ɢ��һЩ�ƾɵ���Ʒ, �����������Ѿ��޷��ֱ������Щ
ʲ�ᶫ����. ǽ��(wall)����һЩ�ʲݵ�����, ǽ�ǵ�һյ������
���Ƶط���һ����΢���Ĺ�â, Ҳʼ����Щ�ֿ�������Ĺ���.

LONG
	);
	set("exits", ([
	"west" : "/d/death/road1",
	]) );
	set("item_desc", ([
	"wall" : @WALL
��������ǿ�ֱ�ó������֣�
�ұ����������ˡ�����Ҫ�ؼ���������
                      ^^^^
                        ���Լ���...
ʲ��п��Լ���?!?!? �����������˶�û��...

�������Լ�ʱ��һ�°�... �Լ��˶��ụ���æ��˵.. 
                                    ^^^^
                                 ��... ȷ... ��?!?!
�.. 
WALL
	]) );
	set("cost", 0);
        setup();
	set("no_fight", 1);
//        replace_program(ROOM);
}
void init()
{
        add_action("do_suicide","suicide");

}

int do_suicide(string arg)
{
        object me = this_player();
        tell_object(me, "�㻹�����ء�\n");
        return 1;
}


