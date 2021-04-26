#include <ansi.h> 
inherit NPC; 

string AskAll(); 
string AskGift(); 

void create() 
{ 
set_name(HIW"������ʹ"NOR, ({ "angel" }) ); 
set("race", "����"); 
set("age", 1); 
set("long", "һ����������ʹ���������������� ��ֻҪ���� 6k exp ��ǰ���Ϳ��Դ�������õ�2000���顢Cuff��Sword��Parry��Force��Dodge�;���200������300�� \n"); 
set("attitude", "peaceful"); 
set("gender", "Ů��"); 
set("age", 18 ); 
set("title", HIG"��������"NOR); 
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
return ""CYN"�����ѯ�����й� gift(����)����Ϣ���츳����ֱ���� "HIC"gift 0 0 2 0"NOR" �����Ƶ�ָ�"NOR"\n"; 
} 

int addGift( string arg ) 
{ 
object me = this_player(); 
int gstr, gin, gcon, gdex; 
if ( me->query( "lostdata/gifts" ) ) 
return notify_fail( "���ù��츳�Ĳ����ˡ�\n" ); 
if ( !arg ) 
return notify_fail( "ָ���ʽ��gift 0 1 1 0, �ܺͱ�����2��������С�0�ġ�\n" ); 
if ( sscanf( arg, "%d %d %d %d", gstr, gin, gcon, gdex ) != 4 ) 
return notify_fail( "ָ���ʽ��gift 0 1 1 0, �ܺͱ�����2��������С�0�ġ�\n" ); 
if ( gstr < 0 || gin < 0 || gcon < 0 || gdex < 0 ) 
return notify_fail( "ÿһ�������0.\n" ); 
if ( (gstr+gin+gcon+gdex) != 2 ) 
return notify_fail( "�ܺͱ�����2.\n" ); 
me->set( "lostdata/gifts", 1 ); 
me->add( "str", gstr ); 
me->add( "int", gin ); 
me->add( "con", gcon ); 
me->add( "dex", gdex ); 
me->save(); 
write( "лл������ݵ�֧�֡���Ϸ��졣\n" ); 
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
return ""CYN"��̫̰���˰ɣ�Ҫ�˻���Ҫ��"NOR"\n";
}

if ( me->query( "combat_exp") > 6000 )  {
return ""CYN"��ľ�����ҵĻ��࣬Ҫ����ʲôѽ��"NOR"\n";
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
return ""CYN"��Ϸ��죡"NOR"\n";
}

