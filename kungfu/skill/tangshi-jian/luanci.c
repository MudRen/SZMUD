// Code Of ShenZhou
// 乱刺 luanci.c
// by keny
/*
（别人所见）只见$1突然运剑如风，向着$2唰、唰急刺两剑之后突然收招，定立于当场，手中$A微微颤抖不止。 
(自己所见）你调整了一下呼吸，将内劲运于腕、指，起手抬剑向着$2唰、唰急刺两剑后立即收招。; 
 
突然$1手腕急抖，运劲于$A，将剑身震出龙吟般的清啸，发出淡淡的银色光芒。
刹哪间剑光满天，四处都是$1的身影。$A逼出的重重罡气将$2打得无处可避，只有狼狈招架着。 
$1剑峰一转，回身反劈向$2，$2刚出手抵挡，$1突然舞了个剑花，$A削向$2的周身。 
只听“嗤”的一声，$2的$B被削下一块，被剑身所发出的罡气逼得满天舞，$B露出了白白的皮肉。围观的人发出一阵轰笑。 
$2气得脸色发青，当下只得咬牙硬着头皮拼下去。 

微微一笑，当下说到“看好了！”，一抖手中的$A复又冲上，来势更加凶猛，初时还可看到$1的身影， 
渐渐地已分不出剑与人，人与剑，只可见一团银雾上下翻舞，左冲右突。 
$1剑身所发出的凛冽罡气,刮在脸上生疼，围观人群中内功稍低者已被逼至丈尺开外。 
只见$2不是发髻被削下一块就是身上的$B被剑风扫中，$2披头散发着狼狈招架，身上的$B被$1手中的$A一条条的削下，犹如破布般满天飞舞，中间加杂着$2的缕缕长发。 
$1忽然纵身跃至圈外，撤剑、收招一气呵成，看着$2大笑不止。 
$2依头一看，身上的$B已经成条缕，随风“卟卟啦啦”的乱飘着，到处露着白白的皮肉。围观的人爆发;出一阵轰堂大笑。 
$2无地自容，气得眼冒金星，喉头一甜，“哇”的喷出一口鲜血。}--->这是pfm结束后出现的描述。 
*/

#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
string armor; 
int skill;

if( !target ) target = offensive_target(me);  
if( !target ||  !target->is_character() || !me->is_fighting(target) )  
return notify_fail("你不在战斗中无法施技。\n");  

if( me->query_temp("yield") )  
return notify_fail("你只挨打，无法施技？\n");  

if( (int)me->query("max_jingli", 1) < 500 )  
return notify_fail("你的精力修为不够，无力施展【乱刺】！\n");  
       
if( (int)me->query("max_neili", 1) < 500 )  
return notify_fail("你的内力修为不够，无力施展【乱刺】！\n");  
       
if( me->query_skill("tangshi-jian",1) < 200 )  
return notify_fail("你躺尸剑不够纯熟！\n");  
              
if( me->query("neili") <= 500 )  
return notify_fail("你的内力不够使用【乱刺】！\n");  
       
if( me->query("jingli") <= 500 )  
return notify_fail("你的精力不够使用【乱刺】！\n"); 

skill = (int)me->query_skill("sword")/2;

message_vision(HIM"只见$N突然运剑如风，向着$n唰、唰急刺两剑之后突然收招，定立于当场，手中"+(me->query_temp("weapon"))->query("name")+HIM"微微颤抖不止。\n\n\n" NOR, me,target);
tell_object(target, HIR"你只觉得敌招来势其乱，令你身上的衣甲尽破！\n" NOR);

message_vision(HIR"$N的剑以乱刺之势在$n身上连刺几击，痛得$n呱呱大叫。\n"NOR, me, target); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
target->start_busy(1+random(2)); 
me->start_busy(1+random(2)); 
me->add("neili", -200);
me->add("jingli", -200);

if( target->query_temp("armor/cloth")){ 
message_vision(HIG "\n突然$N手腕急抖，运劲于"+(me->query_temp("weapon"))->query("name")+HIG"，将剑身震出龙吟般的清啸，发出淡淡的银色光芒。 \n"
"刹哪间剑光满天，四处都是$N的身影，"+(me->query_temp("weapon"))->query("name")+HIG"逼出的重重罡气将$n打得无处可避，只有狼狈招架着。 \n" 
"$N剑峰一转，回身反劈向$n，$n刚出手抵挡，$N突然舞了个剑花，"+(me->query_temp("weapon"))->query("name")+"削向$n的周身。\n" 
"只听“嗤”的一声，$n的"+(target->query_temp("armor/cloth"))->query("name")+HIG"被削下一块，被剑身所发出的罡气逼得满天舞，破"+(target->query_temp("armor/cloth"))->query("name")+HIG"露出了白白的皮肉。围观的人发出一阵轰笑。\n" 
"$n气得脸色发青，当下只得咬牙硬着头皮拼下去。\n\n" NOR, me, target); 
target->start_busy(random(5));
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

message_vision(HIG "\n$N微微一笑，当下说到“看好了！”，一抖手中的"+(me->query_temp("weapon"))->query("name")+HIG"复又冲上，来势更加凶猛，初时还可看到$N的身影，渐渐地已分不出剑与人，人与剑，只可见一团银雾上下翻舞，左冲右突。\n" 
"$N剑身所发出的凛冽罡气,刮在脸上生疼，围观人群中内功稍低者已被逼至丈尺开外。\n" 
"只见$n不是发髻被削下一块就是身上的"+(target->query_temp("armor/cloth"))->query("name")+HIG"被剑风扫中，$n披头散发着狼狈招架，身上的"+(target->query_temp("armor/cloth"))->query("name")+"被$N手中的"+(me->query_temp("weapon"))->query("name")+HIG"一条条的削下，犹如破布般满天飞舞，中间加杂着$n的缕缕长发。\n" 
"$N忽然纵身跃至圈外，撤剑、收招一气呵成，看着$n大笑不止。\n" 
"$n依头一看，身上的"+(target->query_temp("armor/cloth"))->query("name")+HIG"已经成条缕，随风“卟卟啦啦”的乱飘着，到处露着白白的皮肉。围观的人爆发出一阵轰堂大笑。\n" 
"$n无地自容，气得眼冒金星，喉头一甜，“哇”的喷出一口鲜血。\n\n" NOR, me, target);

armor = target->query_temp("armor/cloth"); 
if( armor->query("armor_prop/armor")){ 
armor->unequip(); 
armor->move(environment(target)); 
armor->set("name", "破" + armor->query("name")); 
armor->set("value", 0); 
armor->set("armor_prop/armor", 0); 
me->add("neili", -200);
me->add("jingli", -200);
} 
}

else {
message_vision(YEL"$n身子一侧，轻轻的躲过了$N的攻击。\n\n" NOR, me,target); 
}
me->add("neili", -200); 
me->add("jingli", -200); 
me->start_busy(2); 
return 1;
}
