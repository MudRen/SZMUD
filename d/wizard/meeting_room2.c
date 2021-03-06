// Code of ShenZhou
// Room: /d/wizard/meeting_room.c

inherit ROOM;

void create()
{
        set("short", "侠客聚义厅");
        set("long", @LONG
这是间巨大的圆形会议厅，从地面到天花板都是整块的水磨镜面花冈石。地
上正中有个四四方方的水池，水池中央匍伏着一只半人高的铜龟。龟背上伏着块
千斤石碑，上面书写着龙飞凤舞的两个大字：【神州】。环绕水池沿著东南西北
四个方向各摆放着九把虎皮交椅，面对着会议厅的中心水池。四周的墙上镂刻着
一些古怪的文字。旁边还有许多出口，可以到达一些小规模的会议室。
LONG );

        set("exits", ([
"ctrl"  : "/family_job/control.c",
        "up" : __DIR__"station_room",
        "down" : __DIR__"wizard_room" ]));
        set("item_desc", ([ 
        "map":
        "general:通往天帝与开发神仙的会议室，那是制定和监督项目进度的地方\n"+
        "kungfu :通往功夫技能会议室，那是交流武功、技能和编程经验的地方\n"+
        "quest  :通往情节迷题会议室，那是交流迷题、情节、文字描述的设计和编写经验的地方\n"+
        "npc    :通往非玩家人物会议室，那是交流非玩家人物的设计和编程经验的地方\n"+
        "obj    :通往物品道具会议室，那是交流各种物品道具的设计和编程经验的地方\n"+
        "test   :通往测试调查会议室，那是交流新代码测试、游戏资源调查等经验的地方\n"+
        "room   :通往地图地理会议室，那是交流地图、房间、机关的设计和编程经验的地方\n"+
        "job    :通往工作系统会议室，那是交流工作系统、职业系统的设计和编程经验的地方\n"+
        "guide  :通往大图书馆，那是学习初、中、高级编程知识和向首席开发神仙提问的地方\n",
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
