// Code of ShenZhou
// yejun.c Ҷ��

#include <ansi.h>
inherit NPC;
int learn_message(object ob,string skill); 
#include "/kungfu/class/quanzhen/auto_perform.h" 
string ask_zhang();
void create()

{
set_name(HIM"Ҷ��"NOR, ({ "yejun", "jun" })); 
set("nickname", HIR "�칫�Ҵ���Ա" NOR); 
	set("gender", "����");
	set("age", 19);
set("long", "������Ҷ��-ɳĮ֮�ӵ�ͬ��,�����ɫ��,Ů��С��Ŷ��\n");
	
set("combat_exp", 2000000);
	set("shen_type", -1);

	set("attitude", "heroism");
	
	set_skill("unarmed", 20);
set("max_qi", 6500); 
set("eff_jingli", 9000);
set("max_neili", 60000);
set("neili", 60000); 
set("qi", 6500);  
set("jing", 4000);
set("jingli", 4000);
set("max_jing",4000);
set("jiali", 100);
set_skill("force", 550);
set_skill("sword", 550);
set_skill("quanzhen-jian", 550);
set_skill("xiantian-gong", 550);
set_skill("jinyangong", 550);
set_skill("parry", 550);
set_skill("cuff", 550);
set_skill("kick", 550);
set_skill("strike", 550);
set_skill("sanhua-juding", 550);
set_skill("chunyang-quan", 550);
map_skill("force", "xiantian-gong"); 
map_skill("dodge","jinyangong"); 
map_skill("sword","quanzhen-jian"); 
map_skill("cuff","chunyang-quan"); 
map_skill("strike","sanhua-juding"); 
prepare_skill("cuff", "chunyang-quan"); 
prepare_skill("strike", "sanhua-juding"); 
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

set("chat_chance", 50);
set("chat_msg", ({ 
(: auto_perform :), 
"Ҷ��˵������ʦ�����֪��������ô���ˡ�\n", 
"Ҷ��˵��: ���������smzzȻ���������ɫ���ַ�����,��ʱ�ͺö��������ĵ�Ŷ!\n",
"Ҷ��˵��: ����ʵ��ɳĮ֮�ӵ�ͬ������һ��������,�����ڰ��ҷ�������ú���Ŷ!\n",
"Ҷ��˵��: �����ĸ���������?\n",
"Ҷ��˵��: ����Ĳ�֪��ɳĮ֮���ڸ�ʲô,�ѵ���ôæ��?\n",
}) ); 
	setup();
	carry_object("/clone/misc/cloth")->wear();
set("inquiry", ([ 
"smzz":"�������ҵ�"HIW"�ϰ�"NOR",�����ڲ����ҿ��԰���ɵ�ʲô��?\n",
"�ϰ�":"�ϰ����smzz��,����˵����?���Ǹ�"HIM"��÷Ϸ"NOR"��Ա����һ��\n",
"��÷Ϸ":"�Һ�ɳĮ֮�Ӷ��ǳ���÷Ϸ��Ŷ!��Ҫ����?�ҿ��Ը���"HIY"��һ��"NOR",��������,��������ǿ��ĵ�����?\n",
"��һ��":"���ϵ������˫��,��ˮ��ɽ��Ц��,������?���������Ļ�÷Ϸ������ѡ��,"HIW"�ٳ�һ��"NOR"��?\n",
"�ٳ�һ��":"�㵱���ǻ�������?�ҵ�ɤ�����ⳤ��Ү,�����һ��"HIM"��ɤ��"NOR"���Ҿͳ�\n" 
]));
carry_object("/d/city/obj/changjian")->wield(); 
}
