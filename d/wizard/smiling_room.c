// smiling_room.c 门派组工作室
// by April 01/08/09

inherit ROOM;

void create()
{
        set("short", "门派组工作室");
        set("long", 
				"这是间巨大的锯齿形工作室，从地面到天花板都是整块的...嗯...窗户纸。\n"
				+"地上正中有个锯齿形大方桌(狗尾巴草扎的)，方桌中央匍伏着一只未完工的张牙\n"
				+"舞爪的大青龙(蛇)。几个巫师骑着扫把满屋乱窜(有点象被人追打的苍蝇)，为完\n"
				+"成这个大青龙辛勤工作。目前本组正在编写古墓派，其中:\n\n"
				+"分冥子(scatter)，编写skills \n"
				+"诗馨(jiuer),	 完善地理环境 \n"
				+"黑豹(blacko),	 协助jiuer \n"
				+"劳拉(lara),	测试 \n"
				+"风雨电(Fengyu),	寒玉床 \n"
				+"不再爱你(chchong),	玉女心经的exert,skills描述 \n"
				+"叶枫(lisser),		skills描述 \n"
				+"菱儿(april)，	 玉女心经及其相关练功exert \n\n"
				+"“素手把芙蓉，虚步摄太空；霓衫曳广带，红袖舞飞虹。” \n\n"
				+"我们热忱地希望你加入我们! \n"
				+"欢迎你来画眼睛！ \n\n"
			);

        set("exits", ([
                "east" : __DIR__"meeting_room",
                 ]));

        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("cost", 0);
        setup();

        call_other("/clone/board/menpai_b", "???");
//      replace_program(ROOM);
}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
