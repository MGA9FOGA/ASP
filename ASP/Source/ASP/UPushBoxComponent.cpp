
#include "UPushBoxComponent.h"


UPushBoxComponent::UPushBoxComponent()
{
	UPrimitiveComponent::SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	UPrimitiveComponent::SetCollisionObjectType(ECC_WorldDynamic);

	UPrimitiveComponent::SetCollisionResponseToAllChannels(ECR_Ignore);
	UPrimitiveComponent::SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	SetGenerateOverlapEvents(true);
	SetHiddenInGame(true);
}

float UPushBoxComponent::GetHalfWidth() const
{
	return GetScaledBoxExtent().Y;
}