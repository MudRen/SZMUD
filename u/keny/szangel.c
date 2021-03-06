#include <ansi.h> 
inherit NPC; 

string AskAll(); 
string AskGift(); 

void create() 
{ 
set_name(HIW"新手天使"NOR, ({ "angel" }) ); 
set("race", "人类"); 
set("age", 1); 
set("long", "一个美丽的天使，是神仙们派来的 ，只要你在 6k exp 以前，就可以从她那里得到2000经验、Cuff、Sword、Parry、Force、Dodge和精力200、内力300。 \n"); 
set("attitude", "peaceful"); 
set("gender", "女性"); 
set("age", 18 ); 
set("title", HIG"服务神州"NOR); 
set( "eff_qi", 100000 ); 
set( "eff_jing", 100000 ); 
set("max_qi", 100000); 
set("max_jing", 100000); 
set("max_jingli", 100000); 
set( "eff_jingli", 100000 ); 
set_skill("beauty", 6000);
set( "eff_jing", 100000 ); 
set( "neili", 100000 ); 
set( "max_neili", 100000 ); 
set( "qi", 100000 ); 
set( "jingli", 100000 ); 
set( "jing", 100000 ); 
set( "neili", 100000 ); 
set("str", 100); 
set("con", 100); 
set("dex", 100); 
set("int", 100); 
set("combat_exp", 20000000); 
set_temp("apply/attack", 1000); 
set_temp("apply/damage", 1000); 
set_temp("apply/armor", 1000); 
set("inquiry", ([ 
"all" : (:AskAll:), 
"gift" : (:AskGift:), 
])); 
setup(); 
} 

void init() 
{ 
add_action( "addGift", "gift" ); 
} 

string AskAll() 
{ 
return ""CYN"你可以询问我有关 gift(礼物)的消息，天赋奖励直接用 "HIC"gift 0 0 2 0"NOR" 或类似的指令。"NOR"\n"; 
} 

int addGift( string arg ) 
{ 
object me = this_player(); 
int gstr, gin, gcon, gdex; 
if ( me->query( "lostdata/gifts" ) ) 
return notify_fail( "你拿过天赋的补偿了。\n" ); 
if ( !arg ) 
return notify_fail( "指令格式：gift 0 1 1 0, 总和必须是2，不能有小於0的。\n" ); 
if ( sscanf( arg, "%d %d %d %d", gstr, gin, gcon, gdex ) != 4 ) 
return notify_fail( "指令格式：gift 0 1 1 0, 总和必须是2，不能有小於0的。\n" ); 
if ( gstr < 0 || gin < 0 || gcon < 0 || gdex < 0 ) 
return notify_fail( "每一项必须大於0.\n" ); 
if ( (gstr+gin+gcon+gdex) != 2 ) 
return notify_fail( "总和必须是2.\n" ); 
me->set( "lostdata/gifts", 1 ); 
me->add( "str", gstr ); 
me->add( "int", gin ); 
me->add( "con", gcon ); 
me->add( "dex", gdex ); 
me->save(); 
write( "谢谢你对神州的支持。游戏愉快。\n" ); 
return 1; 
} 


string AskGift()
{
object me = this_player(); 
int ccforce; 
int fforce; 
int ccsword;
int fsword;
int cccuff;
int fcuff;
int ccdodge;
int fdodge;
int ccparry;
int fparry;

ccsword = me->query_skill("sword",1);  
fsword = ccsword + 20; 

cccuff = me->query_skill("cuff",1);  
fcuff = cccuff + 20; 

ccdodge = me->query_skill("dodge",1);  
fdodge = ccdodge + 20; 

ccparry = me->query_skill("parry",1);  
fparry = ccparry + 20; 

ccforce = me->query_skill("force",1); 
fforce = ccforce + 20; 


if ( me->query( "newsite/gift" ) ) {
return ""CYN"你太贪心了吧？要了还想要吗？"NOR"\n";
}

if ( me->query( "combat_exp") > 6000 )  {
return ""CYN"你的经验比我的还多，要来干什么呀？"NOR"\n";
}

me->add("max_neili", 300);
me->add("max_jingli", 200);
me->add("eff_jingli", 200);
me->set_skill("sword", fsword);
me->set_skill("cuff", fcuff);
me->set_skill("force", fforce); 
me->set_skill("dodge", fdodge);
me->set_skill("parry", fparry);
me->add("combat_exp", 2000);
me->set("newsite/gift",1);
return ""CYN"游戏愉快！"NOR"\n";
}

