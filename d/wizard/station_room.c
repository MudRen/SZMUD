// Code of ShenZhou
// /d/wizard/station.c
// by aln 4 / 98

inherit ROOM;

void create()
{
        set("short", "��תվ");
        set("long", @LONG
�����ǡ����ݡ���ʦ���õĿ����ڴ���æµ����ʦ��ÿ�춼������Ҵ�
������û���˹˵���̧ͷ�������װ�ޣ�����Ҳֻ�Ǽ򵥵Ĳ����˼��¡�
LONG );

              set("exits", ([ /* sizeof() == 3 */ 
                      "down"  : "/d/wizard/meeting_room",    
                "jiuer"  : "/u/jiuer/workroom", 
                "felix"  : "/u/felix/workroom", 
                "fanren"  : "/u/fanren/workroom", 
                "gateopen"  : "/u/gateopen/workroom", 
                "athena"  : "/u/athena/workroom", 
                "lnere"  : "/u/lnere/workroom", 
                "naihe"  : "/u/naihe/naihe_room", 
                "hap"  : "/u/hap/workroom", 
                "hongyan"  : "/u/hongyan/workroom", 
                "karlopex"  : "/u/karlopex/workroom", 
                "mafu"  : "/u/mafu/workroom", 
                "mariner"  : "/u/mariner/workroom", 
                "mxj"  : "/u/mxj/workroom", 
                "rama"  : "/u/rama/workroom", 
                "scatter"  : "/u/scatter/workroom", 
                "snowyu"  : "/u/snowyu/workroom", 
                "bwang"  : "/u/bwang/workroom", 
                "hongyan"  : "/u/hongyan/workroom", 
                "ajo"  : "/u/ajo/workroom", 
                "slow"  : "/d/wizard/slowroom", 
]));
		

        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("cost", 0);
        setup();

       call_other("/cmds/usr/news", "???");
//      replace_program(ROOM);
}
void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)")
                me->move("/d/death/death.c");
}
