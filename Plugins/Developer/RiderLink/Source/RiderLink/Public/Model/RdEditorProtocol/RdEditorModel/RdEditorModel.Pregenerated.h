//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.13.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#ifndef RDEDITORMODEL_PREGENERATED_H
#define RDEDITORMODEL_PREGENERATED_H


#include "protocol/Protocol.h"
#include "types/DateTime.h"
#include "impl/RdSignal.h"
#include "impl/RdProperty.h"
#include "impl/RdList.h"
#include "impl/RdSet.h"
#include "impl/RdMap.h"
#include "base/ISerializersOwner.h"
#include "base/IUnknownInstance.h"
#include "serialization/ISerializable.h"
#include "serialization/Polymorphic.h"
#include "serialization/NullableSerializer.h"
#include "serialization/ArraySerializer.h"
#include "serialization/InternedSerializer.h"
#include "serialization/SerializationCtx.h"
#include "serialization/Serializers.h"
#include "ext/RdExtBase.h"
#include "task/RdCall.h"
#include "task/RdEndpoint.h"
#include "task/RdSymmetricCall.h"
#include "std/to_string.h"
#include "std/hash.h"
#include "std/allocator.h"
#include "util/enum.h"
#include "util/gen_util.h"

#include <cstring>
#include <cstdint>
#include <vector>
#include <ctime>

#include "thirdparty.hpp"
#include "instantiations_RdEditorRoot.h"

#include "UE4Library/ConnectionInfo.Pregenerated.h"
#include "UE4Library/UnrealLogEvent.Pregenerated.h"
#include "UE4Library/BlueprintReference.Pregenerated.h"
#include "UE4Library/UClass.Pregenerated.h"
#include "Containers/UnrealString.h"
#include "UE4Library/PlayState.Pregenerated.h"
#include "UE4Library/RequestResultBase.Pregenerated.h"

#include "UE4TypesMarshallers.h"


#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable:4250 )
#pragma warning( disable:4307 )
#pragma warning( disable:4267 )
#pragma warning( disable:4244 )
#pragma warning( disable:4100 )
#endif

/// <summary>
/// <p>Generated from: RdEditorModel.kt:23</p>
/// </summary>
namespace JetBrains {
namespace EditorPlugin {

class RIDERLINK_API RdEditorModel : public rd::RdExtBase {

public:
    struct RdEditorModelSerializersOwner final : public rd::ISerializersOwner {
        void registerSerializersCore(rd::Serializers const& serializers) const override;
    };
    
    static const RdEditorModelSerializersOwner serializersOwner;
    
    

public:
    void connect(rd::Lifetime lifetime, rd::IProtocol const * protocol);
    

private:
    // custom serializers
    using __FStringNullableSerializer = rd::NullableSerializer<rd::Polymorphic<FString>>;

public:
    // constants

protected:
    // fields
    rd::RdProperty<ConnectionInfo, rd::Polymorphic<ConnectionInfo>> connectionInfo_;
    rd::RdSignal<UnrealLogEvent, rd::Polymorphic<UnrealLogEvent>> unrealLog_;
    rd::RdSignal<BlueprintReference, rd::Polymorphic<BlueprintReference>> openBlueprint_;
    rd::RdSignal<UClass, rd::Polymorphic<UClass>> onBlueprintAdded_;
    rd::RdEndpoint<FString, bool, rd::Polymorphic<FString>, rd::Polymorphic<bool>> isBlueprintPathName_;
    rd::RdEndpoint<FString, rd::optional<FString>, rd::Polymorphic<FString>, RdEditorModel::__FStringNullableSerializer> getPathNameByPath_;
    rd::RdCall<int32_t, bool, rd::Polymorphic<int32_t>, rd::Polymorphic<bool>> allowSetForegroundWindow_;
    rd::RdProperty<bool, rd::Polymorphic<bool>> isGameControlModuleInitialized_{false};
    rd::RdSignal<PlayState, rd::Polymorphic<PlayState>> playStateFromEditor_;
    rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> requestPlayFromRider_;
    rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> requestPauseFromRider_;
    rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> requestResumeFromRider_;
    rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> requestStopFromRider_;
    rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> requestFrameSkipFromRider_;
    rd::RdSignal<RequestResultBase, rd::AbstractPolymorphic<RequestResultBase>> notificationReplyFromEditor_;
    rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> playModeFromEditor_;
    rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> playModeFromRider_;
    rd::RdProperty<bool, rd::Polymorphic<bool>> isHotReloadAvailable_{false};
    rd::RdProperty<bool, rd::Polymorphic<bool>> isHotReloadCompiling_{false};
    rd::RdSignal<rd::Void, rd::Polymorphic<rd::Void>> triggerHotReload_;
    

private:
    // initializer
    void initialize();

public:
    // primary ctor
    RdEditorModel(rd::RdProperty<ConnectionInfo, rd::Polymorphic<ConnectionInfo>> connectionInfo_, rd::RdSignal<UnrealLogEvent, rd::Polymorphic<UnrealLogEvent>> unrealLog_, rd::RdSignal<BlueprintReference, rd::Polymorphic<BlueprintReference>> openBlueprint_, rd::RdSignal<UClass, rd::Polymorphic<UClass>> onBlueprintAdded_, rd::RdEndpoint<FString, bool, rd::Polymorphic<FString>, rd::Polymorphic<bool>> isBlueprintPathName_, rd::RdEndpoint<FString, rd::optional<FString>, rd::Polymorphic<FString>, RdEditorModel::__FStringNullableSerializer> getPathNameByPath_, rd::RdCall<int32_t, bool, rd::Polymorphic<int32_t>, rd::Polymorphic<bool>> allowSetForegroundWindow_, rd::RdProperty<bool, rd::Polymorphic<bool>> isGameControlModuleInitialized_, rd::RdSignal<PlayState, rd::Polymorphic<PlayState>> playStateFromEditor_, rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> requestPlayFromRider_, rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> requestPauseFromRider_, rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> requestResumeFromRider_, rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> requestStopFromRider_, rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> requestFrameSkipFromRider_, rd::RdSignal<RequestResultBase, rd::AbstractPolymorphic<RequestResultBase>> notificationReplyFromEditor_, rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> playModeFromEditor_, rd::RdSignal<int32_t, rd::Polymorphic<int32_t>> playModeFromRider_, rd::RdProperty<bool, rd::Polymorphic<bool>> isHotReloadAvailable_, rd::RdProperty<bool, rd::Polymorphic<bool>> isHotReloadCompiling_, rd::RdSignal<rd::Void, rd::Polymorphic<rd::Void>> triggerHotReload_);
    
    // default ctors and dtors
    
    RdEditorModel();
    
    RdEditorModel(RdEditorModel &&) = delete;
    
    RdEditorModel& operator=(RdEditorModel &&) = delete;
    
    virtual ~RdEditorModel() = default;
    
    // reader
    
    // writer
    
    // virtual init
    void init(rd::Lifetime lifetime) const override;
    
    // identify
    void identify(const rd::Identities &identities, rd::RdId const &id) const override;
    
    // getters
    rd::IProperty<ConnectionInfo> const & get_connectionInfo() const;
    rd::ISignal<UnrealLogEvent> const & get_unrealLog() const;
    rd::ISignal<BlueprintReference> const & get_openBlueprint() const;
    rd::ISignal<UClass> const & get_onBlueprintAdded() const;
    rd::RdEndpoint<FString, bool, rd::Polymorphic<FString>, rd::Polymorphic<bool>> const & get_isBlueprintPathName() const;
    rd::RdEndpoint<FString, rd::optional<FString>, rd::Polymorphic<FString>, RdEditorModel::__FStringNullableSerializer> const & get_getPathNameByPath() const;
    rd::RdCall<int32_t, bool, rd::Polymorphic<int32_t>, rd::Polymorphic<bool>> const & get_allowSetForegroundWindow() const;
    rd::IProperty<bool> const & get_isGameControlModuleInitialized() const;
    rd::ISignal<PlayState> const & get_playStateFromEditor() const;
    rd::ISource<int32_t> const & get_requestPlayFromRider() const;
    rd::ISource<int32_t> const & get_requestPauseFromRider() const;
    rd::ISource<int32_t> const & get_requestResumeFromRider() const;
    rd::ISource<int32_t> const & get_requestStopFromRider() const;
    rd::ISource<int32_t> const & get_requestFrameSkipFromRider() const;
    rd::ISignal<RequestResultBase> const & get_notificationReplyFromEditor() const;
    rd::ISignal<int32_t> const & get_playModeFromEditor() const;
    rd::ISource<int32_t> const & get_playModeFromRider() const;
    rd::IProperty<bool> const & get_isHotReloadAvailable() const;
    rd::IProperty<bool> const & get_isHotReloadCompiling() const;
    rd::ISource<rd::Void> const & get_triggerHotReload() const;
    
    // intern

private:
    // equals trait

public:
    // equality operators
    friend bool operator==(const RdEditorModel &lhs, const RdEditorModel &rhs);
    friend bool operator!=(const RdEditorModel &lhs, const RdEditorModel &rhs);
    // hash code trait
    // type name trait
    // static type name trait

private:
    // polymorphic to string
    std::string toString() const override;

public:
    // external to string
    friend std::string to_string(const RdEditorModel & value);
};

}
}

#ifdef _MSC_VER
#pragma warning( pop )
#endif



#endif // RDEDITORMODEL_PREGENERATED_H
